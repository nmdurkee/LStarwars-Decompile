/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6760; label: FUN_004f6760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6760(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_10 [12];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_10;
  FUN_004fb550(*DAT_00917844,local_10,0xc);
  DAT_0091784c = FUN_004f5e30(local_10);
  iVar5 = FUN_004f5eb0(local_10);
  DAT_00917840 = iVar5 + -0xc;
  FUN_004fb550(*DAT_00917844,&DAT_0088ab50,DAT_00917840);
  iVar5 = DAT_0091ce60;
  uVar2 = *(uint *)(DAT_0091ce60 + 0x10);
  piVar1 = (int *)(DAT_0091ce60 + 0x14);
  uVar6 = DAT_00917840 + 0xc;
  *(uint *)(DAT_0091ce60 + 0x10) = uVar2 + uVar6;
  *(uint *)(iVar5 + 0x14) = *piVar1 + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar2,uVar6);
  puVar4 = DAT_00917844;
  uVar3 = *(undefined4 *)(DAT_0091ce60 + 0x14);
  DAT_00917844[2] = *(undefined4 *)(iVar5 + 0x10);
  puVar4[3] = uVar3;
  __security_check_cookie(local_4 ^ (uint)local_10);
  return;
}

