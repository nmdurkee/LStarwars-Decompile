/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59fa80; label: FUN_0059fa80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059fa80(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined8 uVar8;
  
  if (DAT_00951b50 == 0) {
    uVar1 = *(undefined1 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200);
    iVar5 = 0;
    if (0 < DAT_00956608) {
      piVar6 = &DAT_00956438;
      iVar7 = DAT_009513b0;
      do {
        iVar3 = *piVar6;
        if (iVar3 != 0) {
          piVar6[1] = *(int *)(iVar3 + 0x1b4);
          piVar6[2] = *(int *)(iVar3 + 0x1b8);
          piVar6[3] = *(int *)(iVar3 + 0x1bc);
          piVar6[4] = (uint)*(ushort *)(iVar3 + 0x27a);
          if ((((*(int *)(iVar3 + 0xcd0) == 0) || (DAT_00802858 == -1)) ||
              (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x7b5) != DAT_00802858)) ||
             ((*(char *)(iVar3 + 0x280) == -1 || (iVar7 == 0)))) {
LAB_0059fb97:
            *(undefined1 *)((int)piVar6 + 0x2a) = 0xff;
          }
          else {
            if ((*(int *)(iVar7 + 0x108) == 0 && *(int *)(iVar7 + 0x10c) == 0) ||
               (((*(int *)(iVar7 + 0x108) != DAT_00802528 ||
                 (*(int *)(iVar7 + 0x10c) != DAT_0080252c)) &&
                ((bVar4 = FUN_00574d80((int)*(short *)(iVar3 + 0x1064)), iVar7 = DAT_009513b0,
                 0x3e < bVar4 ||
                 (uVar8 = __allshl(), iVar7 = DAT_009513b0,
                 ((uint)uVar8 & *(uint *)(DAT_009513b0 + 0x108)) == 0 &&
                 ((uint)((ulonglong)uVar8 >> 0x20) & *(uint *)(DAT_009513b0 + 0x10c)) == 0))))))
            goto LAB_0059fb97;
            *(undefined1 *)((int)piVar6 + 0x2a) = *(undefined1 *)(*piVar6 + 0x280);
          }
          cVar2 = *(char *)(*piVar6 + 0x107f);
          *(char *)((int)piVar6 + 0x29) = cVar2;
          if ((cVar2 == '\0') && (cVar2 = *(char *)(*piVar6 + 0x107e), cVar2 != '\0')) {
            *(char *)((int)piVar6 + 0x29) = cVar2;
          }
          *(undefined1 *)(piVar6 + 10) = uVar1;
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 0xb;
      } while (iVar5 < DAT_00956608);
    }
  }
  return;
}

