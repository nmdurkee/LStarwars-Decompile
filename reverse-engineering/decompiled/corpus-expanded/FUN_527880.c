/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527880; label: FUN_00527880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527880(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  
  if ((((*(int *)(DAT_009238e4 + 0x4381c) != 0) && (DAT_00923894 != 0)) && (DAT_0092389c != 0)) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,&LAB_005277f0,"Select AI Type"),
     iVar1 != 0)) {
    uVar3 = 0;
    do {
      bVar4 = *(byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x49) == uVar3;
      uVar2 = FUN_00627b80(uVar3,&DAT_00801cb4,bVar4,1,FUN_00527800,(&PTR_s_Circle_00801cd0)[uVar3])
      ;
      FUN_00618e10(iVar1,uVar2);
      if (bVar4) {
        *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
      }
      FUN_006279b0(param_1,iVar1);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 3);
  }
  return;
}

