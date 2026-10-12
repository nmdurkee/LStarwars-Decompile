/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42d000; label: FUN_0042d000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042d000(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  iVar1 = FUN_0055f450();
  iVar1 = *(int *)(iVar1 + 0x128);
  if (iVar1 == DAT_0087b228) {
    uVar2 = 0x75;
    iVar4 = 8;
LAB_0042d0b1:
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),uVar2,param_1 + 0x30);
    if (iVar4 == -1) goto LAB_0042d0e8;
  }
  else {
    if (iVar1 == DAT_0087b0b8) {
      uVar2 = 0x2d;
      iVar4 = 9;
      goto LAB_0042d0b1;
    }
    if (iVar1 != DAT_0087b0c8) {
      if (iVar1 != DAT_0087b11c) goto LAB_0042d0e8;
      uVar2 = 0x34;
      iVar4 = 10;
      goto LAB_0042d0b1;
    }
    iVar1 = 0;
    do {
      if (2 < iVar1) {
        if (iVar4 == -1) {
          iVar4 = 0xb;
        }
        break;
      }
      iVar3 = FUN_005cfac0(&DAT_0087aad8 + iVar1 * 3);
      if ((iVar3 != 0) &&
         (iVar3 = FUN_005d0450(&DAT_0087aad8 + iVar1 * 3,param_1 + 0x148), iVar3 != 0)) {
        if (iVar1 == 0) {
          iVar4 = 0xb;
        }
        else {
          iVar4 = (iVar1 != 1) + 0xc;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar4 == -1);
  }
  FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),iVar4,param_1 + 0x30);
LAB_0042d0e8:
  FUN_0054a910(0x3f333333,0,0,0);
  iVar4 = FUN_0054fa60();
  if (iVar4 < 0x8000) {
    uVar2 = 0x3ecccccd;
  }
  else {
    uVar2 = 0xbecccccd;
  }
  FUN_00549de0(PTR_DAT_008021b4,uVar2,2,0);
  FUN_00549bb0(PTR_DAT_008021b4,0x3f19999a,0x3f19999a,0x3f800000);
  FUN_00681f40("Explode1",param_1 + 0x30);
  return;
}

