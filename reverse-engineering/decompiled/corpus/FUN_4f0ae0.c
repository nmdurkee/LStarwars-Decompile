/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0ae0; label: FUN_004f0ae0
 */

undefined8 FUN_004f0ae0(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  uint uVar3;
  
  iVar5 = (param_1 * 3 + -0x1800) * 0x10;
  puVar6 = (undefined4 *)
           ((*(int *)(&DAT_0297dc80 + iVar5) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar5));
  if (param_4 == 1) {
    uVar3 = *(uint *)(&DAT_0297dc70 + iVar5);
    iVar4 = *(int *)(&DAT_0297dc74 + iVar5);
  }
  else {
    if (param_4 == 2) {
      uVar3 = *(uint *)(&DAT_0297dc78 + iVar5);
      uVar1 = uVar3 + *(uint *)(&DAT_0297dc68 + iVar5);
      iVar2 = uVar1 - param_2;
      iVar4 = ((((int)uVar3 >> 0x1f) + *(int *)(&DAT_0297dc6c + iVar5) +
               (uint)CARRY4(uVar3,*(uint *)(&DAT_0297dc68 + iVar5))) - param_3) -
              (uint)(uVar1 < param_2);
      goto LAB_004f0b39;
    }
    uVar3 = *(uint *)(&DAT_0297dc68 + iVar5);
    iVar4 = *(int *)(&DAT_0297dc6c + iVar5);
  }
  iVar2 = uVar3 + param_2;
  iVar4 = iVar4 + param_3 + (uint)CARRY4(uVar3,param_2);
LAB_004f0b39:
  uVar7 = FUN_004f6de0(*puVar6,iVar2,iVar4,0);
  *(undefined8 *)(&DAT_0297dc70 + iVar5) = uVar7;
  puVar6[2] = (int)uVar7;
  puVar6[3] = *(undefined4 *)(&DAT_0297dc74 + iVar5);
  return *(undefined8 *)(&DAT_0297dc70 + iVar5);
}

