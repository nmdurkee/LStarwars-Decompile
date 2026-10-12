/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x623ca0; label: FUN_00623ca0
 */

void FUN_00623ca0(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_17c [52];
  undefined1 local_148 [260];
  uint local_44;
  
  local_44 = DAT_00829570 ^ (uint)auStack_17c;
  iVar4 = 1 - *(int *)(param_2 + 0xc);
  *(int *)(param_2 + 0xc) = iVar4;
  if (iVar4 == 0) {
    fVar1 = *(float *)(DAT_029110ac + 0x5c);
    fVar2 = *(float *)(DAT_029110ac + 0x58);
    fVar3 = *(float *)(DAT_029110ac + 0x54);
    pcVar5 = "H:%1.2f S:%1.2f V:%1.2f";
  }
  else {
    fVar1 = *(float *)(DAT_029110ac + 0x68);
    fVar2 = *(float *)(DAT_029110ac + 100);
    fVar3 = *(float *)(DAT_029110ac + 0x60);
    pcVar5 = "R:%1.2f G:%1.2f B:%1.2f";
  }
  FUN_004f2740(local_148,pcVar5,(double)fVar3,(double)fVar2,(double)fVar1);
  FUN_00619430(param_2,local_148);
  __security_check_cookie(local_44 ^ (uint)auStack_17c);
  return;
}

