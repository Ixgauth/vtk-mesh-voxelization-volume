#include <vtkSmartPointer.h>
#include <vtkFillHolesFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkCleanPolyData.h>

#include <vtkSelectionNode.h>
#include <vtkInformation.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkIdTypeArray.h>
#include <vtkExtractSelection.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkXMLUnstructuredGridReader.h>

#include <vtkBYUReader.h>
#include <vtkOBJReader.h>
#include <vtkPLYReader.h>
#include <vtkPolyDataReader.h>
#include <vtkSTLReader.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkSphereSource.h>
#include <vtksys/SystemTools.hxx>
#include <vtkGeometryFilter.h>

#include <vtkNamedColors.h>

namespace
{
vtkSmartPointer<vtkPolyData> ReadPolyData(const char *fileName);
}

int main(int argc, char *argv[])
{

  const char *fileName = "../data/clippedData.vtu";

  vtkSmartPointer<vtkXMLUnstructuredGridReader> reader = 
      vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader->SetFileName(fileName);

   reader->Update();

  vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid =
    reader->GetOutput();

  vtkSmartPointer<vtkGeometryFilter> geometryFilter = 
  vtkSmartPointer<vtkGeometryFilter>::New();

  geometryFilter->SetInputData(unstructuredGrid);
  geometryFilter->Update();

    

  vtkSmartPointer<vtkPolyData> input = geometryFilter->GetOutput();

  vtkSmartPointer<vtkNamedColors> colors =
    vtkSmartPointer<vtkNamedColors>::New();

  vtkSmartPointer<vtkFillHolesFilter> fillHolesFilter =
    vtkSmartPointer<vtkFillHolesFilter>::New();
  fillHolesFilter->SetInputData(input);
  fillHolesFilter->SetHoleSize(100000.0);
  fillHolesFilter->Update();

  // Make the triangle winding order consistent
  vtkSmartPointer<vtkPolyDataNormals> normals =
    vtkSmartPointer<vtkPolyDataNormals>::New();
  normals->SetInputData(fillHolesFilter->GetOutput());
  normals->ConsistencyOn();
  normals->SplittingOff();
  normals->Update();

  // Visualize
  // Define viewport ranges
  // (xmin, ymin, xmax, ymax)
  double leftViewport[4] = {0.0, 0.0, 0.5, 1.0};
  double rightViewport[4] = {0.5, 0.0, 1.0, 1.0};

  // Create a mapper and actor
  vtkSmartPointer<vtkPolyDataMapper> originalMapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  originalMapper->SetInputData(input);

  vtkSmartPointer<vtkProperty> backfaceProp =
    vtkSmartPointer<vtkProperty>::New();
  backfaceProp->SetDiffuseColor(colors->GetColor3d("Banana").GetData());

  vtkSmartPointer<vtkActor> originalActor =
    vtkSmartPointer<vtkActor>::New();
  originalActor->SetMapper(originalMapper);
  originalActor->SetBackfaceProperty(backfaceProp);
  originalActor->GetProperty()->SetDiffuseColor(
    colors->GetColor3d("Flesh").GetData());

  vtkSmartPointer<vtkPolyDataMapper> filledMapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  filledMapper->SetInputData(fillHolesFilter->GetOutput());

  vtkSmartPointer<vtkActor> filledActor =
    vtkSmartPointer<vtkActor>::New();
  filledActor->SetMapper(filledMapper);
  filledActor->GetProperty()->SetDiffuseColor(
    colors->GetColor3d("Flesh").GetData());
  filledActor->SetBackfaceProperty(backfaceProp);

  // Create a renderer, render window, and interactor
  vtkSmartPointer<vtkRenderer> leftRenderer =
    vtkSmartPointer<vtkRenderer>::New();
  leftRenderer->SetViewport(leftViewport);

  vtkSmartPointer<vtkRenderer> rightRenderer =
    vtkSmartPointer<vtkRenderer>::New();
  rightRenderer->SetViewport(rightViewport);

  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->SetSize(600,300);

  renderWindow->AddRenderer(leftRenderer);
  renderWindow->AddRenderer(rightRenderer);

  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  // Add the actor to the scene
  leftRenderer->AddActor(originalActor);
  rightRenderer->AddActor(filledActor);
  leftRenderer->SetBackground(colors->GetColor3d("PaleGreen").GetData());

  leftRenderer->GetActiveCamera()->SetPosition(0, -1, 0);
  leftRenderer->GetActiveCamera()->SetFocalPoint(0, 0, 0);
  leftRenderer->GetActiveCamera()->SetViewUp(0, 0, 1);
  leftRenderer->GetActiveCamera()->Azimuth(30);
  leftRenderer->GetActiveCamera()->Elevation(30);

  leftRenderer->ResetCamera();

  rightRenderer->SetBackground(colors->GetColor3d("LightGreen").GetData());

  // Share the camera

  rightRenderer->SetActiveCamera(leftRenderer->GetActiveCamera());
  // Render and interact
  renderWindow->Render();

  renderWindowInteractor->Start();

  return EXIT_SUCCESS;
}
namespace
{
vtkSmartPointer<vtkPolyData> ReadPolyData(const char *fileName)
{
  vtkSmartPointer<vtkPolyData> polyData;
  std::string extension = vtksys::SystemTools::GetFilenameExtension(std::string(fileName));
  
  if(extension == ".vtu")
  {
    
  }
  else
  {
    vtkSmartPointer<vtkSphereSource> source =
      vtkSmartPointer<vtkSphereSource>::New();
    source->Update();
    polyData = source->GetOutput();
  }
  return polyData;
}
}
