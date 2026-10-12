/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501760; label: FUN_00501760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00501760(int *param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *unaff_EDI;
  
  uVar7 = 0;
  if ((char)unaff_EDI[2] != '\0') {
    iVar6 = 0;
    do {
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + uVar7 * 8) = 0;
      puVar1 = (undefined4 *)(iVar3 + uVar7 * 8);
      bVar2 = *(byte *)(unaff_EDI[1] + (uint)*(byte *)(*unaff_EDI + 0x59 + iVar6) * 0xc + 4);
      if ((bVar2 & 8) == 0) {
        if ((bVar2 & 1) == 0) {
          if ((bVar2 & 0x10) != 0) {
            if (DAT_00921314 != (code *)0x0) {
              (*DAT_00921314)(puVar1[1]);
            }
            *puVar1 = 0;
            puVar1[1] = 0xffffffff;
          }
        }
        else if (((*(byte *)(*unaff_EDI + iVar6 + 0x58) & 0x20) != 0) && (-1 < (int)puVar1[1])) {
          FUN_00684400(puVar1 + 1);
        }
      }
      else {
        piVar4 = (int *)puVar1[1];
        if (((short)piVar4[2] != 0) && (iVar3 = *piVar4, iVar3 != 0)) {
          if (*(ushort *)((int)piVar4 + 0xe) != 0) {
            iVar5 = *(int *)(*(int *)(iVar3 + 0xc) + -4 + (uint)*(ushort *)((int)piVar4 + 0xe) * 4);
            *(undefined4 *)(iVar5 + 0x80) = 0;
            *(undefined4 *)(iVar5 + 0x84) = 0;
          }
          if (*(ushort *)(piVar4 + 4) != 0) {
            iVar5 = *(int *)(*(int *)(iVar3 + 0xc) + -4 + (uint)*(ushort *)(piVar4 + 4) * 4);
            *(undefined4 *)(iVar5 + 0x80) = 0;
            *(undefined4 *)(iVar5 + 0x84) = 0;
          }
          if (*(ushort *)((int)piVar4 + 10) != 0) {
            iVar3 = *(int *)(*(int *)(iVar3 + 0xc) + -4 + (uint)*(ushort *)((int)piVar4 + 10) * 4);
            *(undefined4 *)(iVar3 + 0x80) = 0;
            *(undefined4 *)(iVar3 + 0x84) = 0;
          }
        }
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 100;
    } while (uVar7 < *(byte *)(unaff_EDI + 2));
  }
  return;
}

