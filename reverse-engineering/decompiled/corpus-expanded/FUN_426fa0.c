/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x426fa0; label: FUN_00426fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426fa0(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = &DAT_008569c4;
  iVar5 = 10;
  do {
    if (*(char *)(puVar4 + 7) != '\0') {
      puVar4[9] = (float)puVar4[9] + _DAT_00925018;
      FUN_005d6430(puVar4 + 3,puVar4,1,0);
      fVar1 = (float)puVar4[9];
      if (NAN(fVar1) || 10.7 < fVar1 == (fVar1 == 10.7)) {
        if (puVar4[10] != 0) {
          fVar1 = (float)puVar4[9];
          uVar3 = _DAT_007f38f4;
          if ((NAN(fVar1) || 10.0 < fVar1 == (fVar1 == 10.0)) &&
             (((iVar2 = puVar4[6], iVar2 == 0 || (*(char *)(iVar2 + 0x28b) != '\0')) ||
              (fVar1 = *(float *)(iVar2 + 0xde0), NAN(fVar1) || 0.3 < fVar1 == (fVar1 == 0.3))))) {
            uVar3 = _DAT_007f38f8;
          }
          *(undefined4 *)(puVar4[10] + 0xc) = uVar3;
        }
      }
      else {
        FUN_00404e30(puVar4 + -3);
        FUN_00426de0(puVar4,0);
        *(undefined1 *)(puVar4 + 7) = 0;
        if (puVar4[10] != 0) {
          *(undefined4 *)(puVar4[10] + 0x20) = _DAT_007f38fc;
          puVar4[10] = 0;
        }
      }
    }
    puVar4 = puVar4 + 0xe;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

