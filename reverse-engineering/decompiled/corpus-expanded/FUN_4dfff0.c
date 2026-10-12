/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfff0; label: FUN_004dfff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dfff0(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  float10 fVar5;
  short local_4;
  
  iVar4 = 0;
  if (DAT_00951b50 == 0) {
    puVar3 = &DAT_00888fc4;
    do {
      iVar2 = FUN_00467890(*puVar3);
      if (iVar2 != 0) {
        iVar4 = iVar4 + 1;
      }
      puVar3 = puVar3 + 1;
    } while ((int)puVar3 < 0x888fd4);
    if (DAT_00882ac4 == 0) {
      DAT_00882ac4 = FUN_0055ce20((int)DAT_007f19d0,0x400,0,1,0);
      return;
    }
    if (iVar4 != 4) {
      *(undefined4 *)(DAT_00882ac4 + 0x5c) = 0x42e1851f;
      *(undefined4 *)(DAT_00882ac4 + 0x60) = 0x3f400000;
      *(undefined4 *)(DAT_00882ac4 + 100) = 0xc1280000;
      fVar5 = (float10)FUN_005b7d30(_DAT_0092505c,0x40000000);
      local_4 = (short)(int)ROUND((float)(&DAT_029899a0)
                                         [(uint)(int)ROUND(fVar5 * (float10)0.5 * (float10)65536.0)
                                          >> 1 & 0x7fff] * 30.0 * -182.04445);
      *(short *)(DAT_00882ac4 + 0x27a) = -0x4000 - local_4;
      return;
    }
    if (DAT_0093b2a4 != 0) {
      FUN_0057a5b0();
      return;
    }
    iVar4 = FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"ep2_factory_outro",1);
    puVar1 = (uint *)(*(int *)(iVar4 + 4) + 0x88);
    *puVar1 = *puVar1 | 2;
  }
  return;
}

