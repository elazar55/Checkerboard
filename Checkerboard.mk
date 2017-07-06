##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Checkerboard
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Administrator/Documents/C++
ProjectPath            :=C:/Users/Administrator/Documents/C++/Checkerboard
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=06/07/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/Dev/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/Dev/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Checkerboard.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/Dev/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Dev\SDL2-2.0.5\i686-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Dev\GLEW\include $(IncludeSwitch)C:\Dev\GLM 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 $(LibrarySwitch)opengl32 $(LibrarySwitch)glew32 
ArLibs                 :=  "mingw32" "SDL2main" "SDL2" "opengl32" "glew32" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Dev\SDL2-2.0.5\i686-w64-mingw32\lib $(LibraryPathSwitch)C:\Dev\GLEW\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Dev/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/Dev/TDM-GCC-32/bin/g++.exe
CC       := C:/Dev/TDM-GCC-32/bin/gcc.exe
CXXFLAGS := -std=c++11 -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Dev/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Program.cpp$(ObjectSuffix) $(IntermediateDirectory)/Framework.cpp$(ObjectSuffix) $(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) $(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IntermediateDirectory)/Mouse.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Program.cpp$(ObjectSuffix): Program.cpp $(IntermediateDirectory)/Program.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/Program.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Program.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Program.cpp$(DependSuffix): Program.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Program.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Program.cpp$(DependSuffix) -MM Program.cpp

$(IntermediateDirectory)/Program.cpp$(PreprocessSuffix): Program.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Program.cpp$(PreprocessSuffix) Program.cpp

$(IntermediateDirectory)/Framework.cpp$(ObjectSuffix): Framework.cpp $(IntermediateDirectory)/Framework.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/Framework.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Framework.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Framework.cpp$(DependSuffix): Framework.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Framework.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Framework.cpp$(DependSuffix) -MM Framework.cpp

$(IntermediateDirectory)/Framework.cpp$(PreprocessSuffix): Framework.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Framework.cpp$(PreprocessSuffix) Framework.cpp

$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix): Grid.cpp $(IntermediateDirectory)/Grid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/Grid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Grid.cpp$(DependSuffix): Grid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Grid.cpp$(DependSuffix) -MM Grid.cpp

$(IntermediateDirectory)/Grid.cpp$(PreprocessSuffix): Grid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Grid.cpp$(PreprocessSuffix) Grid.cpp

$(IntermediateDirectory)/Window.cpp$(ObjectSuffix): Window.cpp $(IntermediateDirectory)/Window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/Window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Window.cpp$(DependSuffix): Window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Window.cpp$(DependSuffix) -MM Window.cpp

$(IntermediateDirectory)/Window.cpp$(PreprocessSuffix): Window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Window.cpp$(PreprocessSuffix) Window.cpp

$(IntermediateDirectory)/Mouse.cpp$(ObjectSuffix): Mouse.cpp $(IntermediateDirectory)/Mouse.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/C++/Checkerboard/Mouse.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Mouse.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Mouse.cpp$(DependSuffix): Mouse.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Mouse.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Mouse.cpp$(DependSuffix) -MM Mouse.cpp

$(IntermediateDirectory)/Mouse.cpp$(PreprocessSuffix): Mouse.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Mouse.cpp$(PreprocessSuffix) Mouse.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


