#include <ttkTopologicalSimplificationHelper.h>
#include <ttkScalarFieldCriticalPoints.h>

#include <vtkSmartPointer.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkDataSet.h>
#include <vtkThreshold.h>
#include <vtkUnstructuredGrid.h>
#include <vtkThresholdPoints.h>
#include <vtkPolyData.h>
#include <vtkFloatArray.h>
#include <vtkThresholdPoints.h>
#include <vtkPolyDataToImageStencil.h>
#include <vtkImageStencilToImage.h>
#include <vtkImageData.h>
#include <vtkFillHolesFilter.h>
#include <vtkGeometryFilter.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkProgrammableFilter.h>

double obtainVolumeFromClosedMesh(vtkSmartPointer<vtkPolyData> polyData, double spacingFactor)
{
   vtkSmartPointer<vtkImageData> whiteImage =
    vtkSmartPointer<vtkImageData>::New();

  // get us the bounds of the sphere in x,y,z (both min and max)
  double bounds[6];
  polyData->GetBounds(bounds);

  double spacing[3];
  spacing[0] =  spacingFactor;
  spacing[1] =  spacingFactor;
  spacing[2] =  spacingFactor;
  whiteImage->SetSpacing(spacing);
  double finalSpaceFactor = spacing[0]*spacing[1]*spacing[2];

  // compute dimensions (size of max - min in each direction)
  int dim[3];
  for (int i = 0; i < 3; i++)
  {
    dim[i] = static_cast<int>(ceil((bounds[i * 2 + 1] - bounds[i * 2]) / spacing[i]));
  }

  whiteImage->SetDimensions(dim);
  whiteImage->SetExtent(0, dim[0] - 1, 0, dim[1] - 1, 0, dim[2] - 1);

  double origin[3];
  origin[0] = bounds[0] + spacing[0] / 2;
  origin[1] = bounds[2] + spacing[1] / 2;
  origin[2] = bounds[4] + spacing[2] / 2;

  whiteImage->SetOrigin(origin);
  whiteImage->AllocateScalars(VTK_UNSIGNED_CHAR,1);

  //white if in black if outside the volume
  unsigned char inval = 255;
  unsigned char outval = 0;

  vtkIdType count = whiteImage->GetNumberOfPoints();

  for (vtkIdType i = 0; i < count; ++i)
  {
    whiteImage->GetPointData()->GetScalars()->SetTuple1(i, inval);
  }


  vtkSmartPointer<vtkPolyDataToImageStencil> pol2stenc =
    vtkSmartPointer<vtkPolyDataToImageStencil>::New();

  pol2stenc->SetInputData(polyData);
  pol2stenc->SetOutputOrigin(origin);
  pol2stenc->SetOutputSpacing(spacing);
  pol2stenc->SetOutputWholeExtent(whiteImage->GetExtent());
  pol2stenc->Update();

  vtkSmartPointer<vtkImageStencilToImage> sten2im =
    vtkSmartPointer<vtkImageStencilToImage>::New();

  vtkSmartPointer<vtkImageData> imageData =
    vtkSmartPointer<vtkImageData>::New();


  sten2im->SetInputConnection(pol2stenc->GetOutputPort());
  sten2im->SetOutsideValue(0);
  sten2im->SetInsideValue(255);
  sten2im->SetOutput(imageData);
  sten2im->Update();

  int* dimensions = imageData -> GetDimensions();

  cout << "Dimensions:  x: " << dimensions[0] << " y: " << dimensions[1] << " z: " << dimensions[2] << endl;

  cout << "Number of points: " << imageData -> GetNumberOfPoints() << endl;
  cout << "Number of cells: " << imageData->GetNumberOfPoints() << endl;

  int numberOfPointsAboveZero = 0;

  for(int z = 0; z < dimensions[2]; z++)
  {
    for(int y = 0; y < dimensions[1]; y++)
    {
      for(int x = 0; x < dimensions[0]; x++)
      {
        double pixel = imageData->GetScalarComponentAsDouble(x, y, z, 0);
        if(pixel > 127)
        {
          numberOfPointsAboveZero++;
        }
      }
    }
  }
  cout << numberOfPointsAboveZero << endl;

  double output = numberOfPointsAboveZero*finalSpaceFactor;

  return output;

}

vtkSmartPointer<vtkPolyData> obtainClosedPolyData(vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid)
{
  vtkSmartPointer<vtkGeometryFilter> geometryFilter = 
  vtkSmartPointer<vtkGeometryFilter>::New();

  geometryFilter->SetInputData(unstructuredGrid);
  geometryFilter->Update();

  vtkSmartPointer<vtkPolyData> input = geometryFilter->GetOutput();

  vtkSmartPointer<vtkFillHolesFilter> fillHolesFilter =
    vtkSmartPointer<vtkFillHolesFilter>::New();
  fillHolesFilter->SetInputData(input);
  fillHolesFilter->SetHoleSize(100000.0);
  fillHolesFilter->Update();

  vtkSmartPointer<vtkPolyData> output = fillHolesFilter->GetOutput();

  return output;
}



int main(int argc, char *argv[])
{
	const char *fileName = "../data/multiGaussianFunctionTestData.vtu";

	vtkSmartPointer<vtkXMLUnstructuredGridReader> reader = 
      vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  	reader->SetFileName(fileName);

  	reader->Update();

  	vtkSmartPointer<ttkScalarFieldCriticalPoints> critPointsFilter = 
  	  vtkSmartPointer<ttkScalarFieldCriticalPoints>::New();

  	critPointsFilter->SetInputConnection(reader->GetOutputPort());

  	critPointsFilter->Update();

  	vtkSmartPointer<vtkDataSet> critPointsOutput = 
  	  critPointsFilter->GetOutput();

  	std::cout << critPointsOutput->GetNumberOfPoints() << endl;

  	double point[3];
  	double scalar[1];

  	vtkSmartPointer<vtkFloatArray> scalars = 
  	  vtkSmartPointer<vtkFloatArray>::New();



  	for(int i = 0; i < critPointsOutput->GetNumberOfPoints(); i++)
  	{

  		critPointsOutput->GetPoint(i,point);
  		scalar[0] = point[2];
  		scalars->InsertNextTuple(scalar);
  	}

  	critPointsOutput->GetPointData()->SetScalars(scalars);

  	for(int i = 0; i < 5; i++)
  	{
  		critPointsOutput->GetPoint(i,point);

  		cout << "Point value: " << point[2] << endl;

  	}

  	vtkSmartPointer<vtkThresholdPoints> criticalPairs = 
      vtkSmartPointer<vtkThresholdPoints>::New();
    criticalPairs->SetInputConnection(critPointsFilter->GetOutputPort());
    criticalPairs->ThresholdBetween(point[2], point[2]);
    criticalPairs->SetInputArrayToProcess(0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_POINTS, vtkDataSetAttributes::SCALARS);

    criticalPairs->Update();

    vtkSmartPointer<vtkPolyData> threshOut = 
      criticalPairs->GetOutput();

 	vtkSmartPointer<ttkTopologicalSimplificationHelper> topologicalSimplificationHelper =
      vtkSmartPointer<ttkTopologicalSimplificationHelper>::New();

    topologicalSimplificationHelper->SetInputConnection(0, reader->GetOutputPort());
    topologicalSimplificationHelper->SetInputConnection(1, criticalPairs->GetOutputPort());

    topologicalSimplificationHelper->Update();

    vtkSmartPointer<vtkDataSet> simplifiedImage = topologicalSimplificationHelper->GetOutput();

    vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid = 
      vtkSmartPointer<vtkUnstructuredGrid>::New();

    unstructuredGrid->CopyStructure(simplifiedImage);

    vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer =
      vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
  	writer->SetFileName("../data/multiGaussianFunctionTestDataOutput.vtu");

  	writer->SetInputData(unstructuredGrid);

  	writer->Write();

    vtkSmartPointer<vtkPolyData> finalOutput = obtainClosedPolyData(unstructuredGrid);

  	double volume = obtainVolumeFromClosedMesh(finalOutput, .0625);

  	cout << "The total volume is: " << volume << endl;

}