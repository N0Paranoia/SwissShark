##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SwissShak
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Tijn\Documents\GitHub\SwissShark"
ProjectPath            := "C:\Users\Tijn\Documents\GitHub\SwissShark"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tijn
Date                   :=11/06/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/Compilers/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/Compilers/MinGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="SwissShak.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/Compilers/MinGW/bin/windres.exe
LinkOptions            :=  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/Compilers/MinGW/include/SDL2 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/Compilers/MinGW/bin 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Compilers/MinGW/bin/ar.exe rcu
CXX      := C:/Compilers/MinGW/bin/g++.exe
CC       := C:/Compilers/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Compilers/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) $(IntermediateDirectory)/Doors.cpp$(ObjectSuffix) $(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/Textures.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) $(IntermediateDirectory)/Timer.cpp$(ObjectSuffix) $(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Objects.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix): Camera.cpp $(IntermediateDirectory)/Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Camera.cpp$(DependSuffix): Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Camera.cpp$(DependSuffix) -MM "Camera.cpp"

$(IntermediateDirectory)/Camera.cpp$(PreprocessSuffix): Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Camera.cpp$(PreprocessSuffix) "Camera.cpp"

$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix): Collision.cpp $(IntermediateDirectory)/Collision.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Collision.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Collision.cpp$(DependSuffix): Collision.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Collision.cpp$(DependSuffix) -MM "Collision.cpp"

$(IntermediateDirectory)/Collision.cpp$(PreprocessSuffix): Collision.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Collision.cpp$(PreprocessSuffix) "Collision.cpp"

$(IntermediateDirectory)/Doors.cpp$(ObjectSuffix): Doors.cpp $(IntermediateDirectory)/Doors.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Doors.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Doors.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Doors.cpp$(DependSuffix): Doors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Doors.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Doors.cpp$(DependSuffix) -MM "Doors.cpp"

$(IntermediateDirectory)/Doors.cpp$(PreprocessSuffix): Doors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Doors.cpp$(PreprocessSuffix) "Doors.cpp"

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM "Player.cpp"

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) "Player.cpp"

$(IntermediateDirectory)/Textures.cpp$(ObjectSuffix): Textures.cpp $(IntermediateDirectory)/Textures.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Textures.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Textures.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Textures.cpp$(DependSuffix): Textures.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Textures.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Textures.cpp$(DependSuffix) -MM "Textures.cpp"

$(IntermediateDirectory)/Textures.cpp$(PreprocessSuffix): Textures.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Textures.cpp$(PreprocessSuffix) "Textures.cpp"

$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix): Tile.cpp $(IntermediateDirectory)/Tile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tile.cpp$(DependSuffix): Tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tile.cpp$(DependSuffix) -MM "Tile.cpp"

$(IntermediateDirectory)/Tile.cpp$(PreprocessSuffix): Tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tile.cpp$(PreprocessSuffix) "Tile.cpp"

$(IntermediateDirectory)/Timer.cpp$(ObjectSuffix): Timer.cpp $(IntermediateDirectory)/Timer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Timer.cpp$(DependSuffix): Timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Timer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Timer.cpp$(DependSuffix) -MM "Timer.cpp"

$(IntermediateDirectory)/Timer.cpp$(PreprocessSuffix): Timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Timer.cpp$(PreprocessSuffix) "Timer.cpp"

$(IntermediateDirectory)/World.cpp$(ObjectSuffix): World.cpp $(IntermediateDirectory)/World.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/World.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/World.cpp$(DependSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/World.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/World.cpp$(DependSuffix) -MM "World.cpp"

$(IntermediateDirectory)/World.cpp$(PreprocessSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/World.cpp$(PreprocessSuffix) "World.cpp"

$(IntermediateDirectory)/Game.cpp$(ObjectSuffix): Game.cpp $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game.cpp$(DependSuffix) -MM "Game.cpp"

$(IntermediateDirectory)/Game.cpp$(PreprocessSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix) "Game.cpp"

$(IntermediateDirectory)/Objects.cpp$(ObjectSuffix): Objects.cpp $(IntermediateDirectory)/Objects.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Tijn/Documents/GitHub/SwissShark/Objects.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Objects.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Objects.cpp$(DependSuffix): Objects.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Objects.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Objects.cpp$(DependSuffix) -MM "Objects.cpp"

$(IntermediateDirectory)/Objects.cpp$(PreprocessSuffix): Objects.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Objects.cpp$(PreprocessSuffix) "Objects.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


