/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dde30; label: FUN_006dde30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dde30(undefined4 param_1,undefined4 param_2)

{
  int X;
  int Y;
  
  _DAT_02975c40 = param_1;
  _DAT_02975c44 = param_2;
  X = FUN_006e6b90();
  Y = FUN_006e6b90();
  SetCursorPos(X,Y);
  FUN_006e5800(X,Y);
  return;
}

