/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6dde30; label: FUN_006dde30
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

