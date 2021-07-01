import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS)
helper.set_dll_def('src/layer_window.def').set_libs(['layer_window']).call(DefaultEnvironment)

SConscriptFiles = ['src/SConscript', 'demos/SConscript', 'tests/SConscript']
helper.SConscript(SConscriptFiles)
