/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6ccf00; label: FUN_006ccf00
 */

void FUN_006ccf00(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int local_d8 [3];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c4 [64];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_d8;
  iVar2 = FUN_00633440(0x78,1);
  if (iVar2 != 0) {
    iVar2 = FUN_006c5af0();
    uVar1 = DAT_0081f9ec;
    uVar5 = DAT_0081f9e8;
    if (iVar2 != 0) {
      local_cc = DAT_0081f9f0;
      local_c8 = DAT_0081f9f4;
      iVar3 = FUN_006c8760(2,DAT_02973ac4,local_c4,0x40);
      if (iVar3 == 0) {
        FUN_004f1f10(local_c4,"no name");
      }
      FUN_004f2740(local_84,"%s - %s",*(undefined4 *)*param_1,local_c4);
      puVar4 = (undefined4 *)FUN_00619250(uVar5,uVar1,local_cc,local_c8,DAT_02973a78,0,local_84);
      if (puVar4 != (undefined4 *)0x0) {
        FUN_006c5920(puVar4,*param_1,param_1[1],0);
        puVar4[2] = *puVar4;
        FUN_006242b0(puVar4,5);
      }
      FUN_00619300(puVar4,local_d8[0] + 0x2c);
      *(undefined4 **)(iVar2 + 8) = puVar4;
      *(undefined4 *)(iVar2 + 0x10) = *param_1;
      *(undefined4 *)(iVar2 + 0x14) = param_1[1];
      *(undefined4 *)(iVar2 + 0x18) = param_1[2];
      *(undefined4 *)(iVar2 + 0x70) = 1;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      if (PTR_PTR_0081fa90 == (undefined *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(PTR_PTR_0081fa90 + 0x10);
      }
      FUN_006bdf00(uVar5);
    }
    __security_check_cookie(local_4 ^ (uint)local_d8);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_d8);
  return;
}

