/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59e760; label: FUN_0059e760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059e760(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  
  if (DAT_00956428 != 0) {
    piVar3 = *(int **)(DAT_00956428 + 0xc);
    *(undefined1 *)(DAT_00956428 + 3) = 0;
    DAT_00956410 = -1;
    DAT_009562fc = 0;
    DAT_009562c1 = '\0';
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)FUN_00559610(DAT_00956418,DAT_0095641c,0xc);
      uVar2 = DAT_0095641c;
      *(int **)(DAT_00956428 + 0xc) = piVar3;
      uVar6 = DAT_00956418;
      iVar4 = DAT_00956340;
      piVar3[1] = DAT_00956340;
      iVar4 = FUN_00559610(uVar6,uVar2,iVar4 * 4);
      piVar3[2] = iVar4;
      *piVar3 = 0;
    }
    FUN_004f1f10(&DAT_009562c8,&DAT_007516c0);
    FUN_004f10e0(param_1,&PTR_DAT_00805618);
    iVar4 = FUN_004fc5b0(param_1);
    while (iVar4 != 0) {
      FUN_004f7fb0(param_1);
      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
      if (iVar4 == 0) break;
      FUN_004fa020(param_1);
      iVar4 = FUN_004fc5b0(param_1);
    }
    FUN_004f11e0(param_1);
    if ((-1 < DAT_00956410) && (iVar4 = FUN_004f1ff0(&DAT_009562c8), iVar4 != 0)) {
      iVar4 = FUN_004f1ff0(&DAT_009562c8);
      iVar5 = FUN_004f1ff0(*(int *)(DAT_0093b268 + 8) + 0x20 + DAT_00956410 * 0x9c);
      uVar6 = FUN_00559610(DAT_00956418,DAT_0095641c,8);
      *(undefined4 *)(piVar3[2] + *piVar3 * 4) = uVar6;
      uVar6 = FUN_00559610(DAT_00956418,DAT_0095641c,iVar4 + iVar5 + 1);
      *(undefined4 *)(*(int *)(piVar3[2] + *piVar3 * 4) + 4) = uVar6;
      FUN_004f1f10(*(undefined4 *)(*(int *)(piVar3[2] + *piVar3 * 4) + 4),&DAT_009562c8);
      if (DAT_00956410 == DAT_008061b8) {
        uVar6 = FUN_005b0550(0,_DAT_00956348,(int)DAT_009562c1);
        **(undefined4 **)(piVar3[2] + *piVar3 * 4) = uVar6;
      }
      else if (DAT_00956410 == DAT_00806144) {
        uVar6 = FUN_005b01b0(0,DAT_009562c4,&DAT_00956300);
        **(undefined4 **)(piVar3[2] + *piVar3 * 4) = uVar6;
      }
      else if (DAT_00956410 == DAT_00805ebc) {
        uVar6 = FUN_005ae1c0(0);
        **(undefined4 **)(piVar3[2] + *piVar3 * 4) = uVar6;
        piVar1 = *(int **)(piVar3[2] + *piVar3 * 4);
        if (*piVar1 != 0) {
          FUN_004f1f10(piVar1[1],*(int *)(DAT_0093b268 + 8) + 0x20 + DAT_00956410 * 0x9c);
          iVar4 = FUN_004f1ff0(*(int *)(DAT_0093b268 + 8) + 0x20 + DAT_00956410 * 0x9c);
          FUN_004f1ec0(*(undefined4 *)(*(int *)(piVar3[2] + *piVar3 * 4) + 4),&DAT_009562c8,
                       0x20 - iVar4);
        }
      }
      else {
        uVar6 = FUN_0055a020(*DAT_00956420,DAT_00956410,&DAT_009562c8);
        **(undefined4 **)(piVar3[2] + *piVar3 * 4) = uVar6;
        if (**(int **)(piVar3[2] + *piVar3 * 4) == 0) {
          FUN_0059d770(&DAT_009562c8,DAT_00956410);
        }
      }
      *piVar3 = *piVar3 + 1;
      uVar7 = (uint)(short)DAT_009562fc;
      *(ushort *)(DAT_00956428 + 10) =
           ((((((ushort)((uVar7 >> 4 & 1) << 5) | (ushort)(uVar7 >> 7) & 1) * 2 |
              (ushort)(uVar7 >> 2) & 1) * 4 | (ushort)(uVar7 >> 3) & 1) * 2 |
            (ushort)(uVar7 >> 1) & 1) * 2 | DAT_009562fc & 1) * 4 |
           ~(ushort)((uVar7 >> 6) << 0xd) & 0x2000 | ~(ushort)((uVar7 >> 5) << 0xe) & 0x4000 |
           *(ushort *)(DAT_00956428 + 10) & 0x8f23;
    }
  }
  return;
}

