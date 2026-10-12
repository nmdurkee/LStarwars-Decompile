/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x623a20; label: FUN_00623a20
 */

void FUN_00623a20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_178 [48];
  undefined1 auStack_148 [260];
  uint local_44;
  
  iVar4 = DAT_029110ac;
  local_44 = DAT_00829570 ^ (uint)auStack_178;
  (*DAT_02900a58)(param_1,param_2,param_3,param_4);
  if (*(int *)(DAT_02910c90 + 0xc) == 0) {
    fVar1 = *(float *)(iVar4 + 0x5c);
    fVar2 = *(float *)(iVar4 + 0x58);
    fVar3 = *(float *)(iVar4 + 0x54);
    pcVar5 = "H:%1.2f S:%1.2f V:%1.2f";
  }
  else {
    fVar1 = *(float *)(iVar4 + 0x68);
    fVar2 = *(float *)(iVar4 + 100);
    fVar3 = *(float *)(iVar4 + 0x60);
    pcVar5 = "R:%1.2f G:%1.2f B:%1.2f";
  }
  FUN_004f2740(auStack_148,pcVar5,(double)fVar3,(double)fVar2,(double)fVar1);
  FUN_00619430(DAT_02910c90,auStack_148);
  __security_check_cookie(local_44 ^ (uint)auStack_178);
  return;
}

