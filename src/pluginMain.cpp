#include <maya/MFnPlugin.h>
#include <maya/MGlobal.h>

MStatus initializePlugin(MObject obj){
    MFnPlugin plugin(obj,"Autodesk","1.0","Any");
    MGlobal::executeCommandOnIdle("print(\"Happy New Year 2024.\\\n\")");
    return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj){
    MFnPlugin plugin(obj,"Autodesk","1.0","Any");
    return MS::kSuccess;
}