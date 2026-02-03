rs_sources = files(
  'random_string.c',
)

if host_system == 'windows'
  rs_sources += rc_lib_gen.process(win32ver_rc, extra_args: [
    '--NAME', 'random_string',
    '--FILEDESC', 'random_string - functions for generating random strings',])
endif

random_string = shared_module('random_string',
  rs_sources,
  kwargs: contrib_mod_args,
)
contrib_targets += random_string

install_data(
  'random_string.control',
  'random_string--1.0.sql',
  kwargs: contrib_data_args,
)
