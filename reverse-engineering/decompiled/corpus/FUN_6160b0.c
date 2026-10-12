/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6160b0; label: FUN_006160b0
 */

void FUN_006160b0(int param_1)

{
  short sVar1;
  int *piVar2;
  undefined1 auStack_110 [4];
  undefined4 local_10c;
  undefined1 local_104 [244];
  uint uStack_10;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_110;
  if (*(short *)(param_1 + 2) == 1) {
    local_10c = 1;
  }
  sVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + 0x14) + 0x30))
                    (*(undefined4 *)(param_1 + 0xc),local_104,0x100);
  FUN_006be780(*(undefined4 *)(param_1 + 0x10));
  piVar2 = (int *)FUN_00615f40(sVar1 + 10);
  if (piVar2[1] != 0) {
    FUN_004ef660(piVar2[3] + piVar2[1],&stack0xfffffee7,1);
    piVar2[3] = piVar2[3] + 1;
  }
  if (piVar2[1] != 0) {
    FUN_004ef660(piVar2[3] + piVar2[1],param_1 + 2,2);
    if (*piVar2 != 0) {
      FUN_00621180(piVar2[3] + piVar2[1]);
    }
    piVar2[3] = piVar2[3] + 2;
  }
  if (piVar2[1] != 0) {
    FUN_004ef660(piVar2[3] + piVar2[1],&stack0xfffffeec,2);
    if (*piVar2 != 0) {
      FUN_00621180(piVar2[3] + piVar2[1]);
    }
    piVar2[3] = piVar2[3] + 2;
  }
  if (piVar2[1] != 0) {
    FUN_004ef660(piVar2[3] + piVar2[1],&stack0xfffffee8,2);
    if (*piVar2 != 0) {
      FUN_00621180(piVar2[3] + piVar2[1]);
    }
    piVar2[3] = piVar2[3] + 2;
  }
  if ((0 < sVar1) && (piVar2[1] != 0)) {
    FUN_004ef660(piVar2[3] + piVar2[1],auStack_110,(int)sVar1);
    piVar2[3] = piVar2[3] + (int)sVar1;
  }
  __security_check_cookie(uStack_10 ^ (uint)&stack0xfffffee4);
  return;
}

