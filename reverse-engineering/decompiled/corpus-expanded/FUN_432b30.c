/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432b30; label: FUN_00432b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432b30(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  fVar4 = (float10)FUN_005b9ef0(&DAT_00802538);
  fVar1 = (float)(fVar4 * (float10)100.0 + (float10)1.0);
  if (*(float *)(param_1 + 0xfc) < 1.0) {
    uVar2 = FUN_006e6b90(_DAT_00925018,0,0,0);
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x938),
                 param_1 + 0x30,uVar2);
    return;
  }
  if (*(float *)(param_1 + 0xfc) < 2.0) {
    if (fVar1 < 10.0) {
      uVar2 = FUN_0054fa60(0);
      uVar2 = FUN_0054fa60(uVar2);
      uVar2 = FUN_006e6b90(_DAT_00925018,uVar2);
      FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x960),
                   param_1 + 0x30,uVar2);
      return;
    }
    if (fVar1 <= 90.0) {
      return;
    }
    uVar2 = FUN_0054fa60(0);
    uVar2 = FUN_0054fa60(uVar2);
    uVar2 = FUN_006e6b90(_DAT_00925018,uVar2);
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x960),
                 param_1 + 0x30,uVar2);
    return;
  }
  if (5.0 <= *(float *)(param_1 + 0xfc)) {
    if (10.0 <= *(float *)(param_1 + 0xfc)) {
      return;
    }
  }
  else {
    if (fVar1 < 10.0) {
      uVar2 = FUN_0054fa60(0);
      uVar3 = FUN_0054fa60(uVar2);
      uVar5 = 0xf;
      uVar2 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x960);
    }
    else {
      if (fVar1 <= 70.0) goto LAB_00432d39;
      uVar2 = FUN_0054fa60(0);
      uVar3 = FUN_0054fa60(uVar2);
      uVar5 = 0x1e;
      uVar2 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x960);
    }
    FUN_00684be0(uVar2,param_1 + 0x30,uVar5,_DAT_00925018,uVar3);
  }
LAB_00432d39:
  if (fVar1 < 30.0) {
    uVar2 = FUN_0054fa60(0);
    uVar2 = FUN_0054fa60(uVar2);
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x94c),
                 param_1 + 0x30,1,_DAT_00925018,uVar2);
    return;
  }
  if (70.0 <= fVar1) {
    uVar2 = FUN_0054fa60(0);
    uVar2 = FUN_0054fa60(uVar2);
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x94c),
                 param_1 + 0x30,0x14,_DAT_00925018,uVar2);
    return;
  }
  uVar2 = FUN_0054fa60(0);
  uVar2 = FUN_0054fa60(uVar2);
  FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x94c),
               param_1 + 0x30,3,_DAT_00925018,uVar2);
  return;
}

