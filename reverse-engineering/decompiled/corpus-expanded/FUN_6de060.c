/* Ghidra pseudocode, not original source.
 * ev_ed8379466d952c1ee28599ad459362d78654b4c0ec0ca4c18c489e481aca6c51
 * Entry: 0x6de060; label: FUN_006de060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006de060(void)

{
  FUN_006db1c0();
  DestroyWindow(DAT_00924864);
  FUN_006dfdc0();
  FUN_006df0c0();
  FUN_006dfdf0();
  CoUninitialize();
  SystemParametersInfoA(0x11,DAT_02975c60,(PVOID)0x0,2);
  SystemParametersInfoA(0x3b,8,&DAT_0082763c,0);
  SystemParametersInfoA(0x35,8,&DAT_00827644,0);
  SystemParametersInfoA(0x33,0x18,&DAT_0082764c,0);
  FUN_006dd2e0();
  SetThreadExecutionState(0x80000000);
  return;
}

