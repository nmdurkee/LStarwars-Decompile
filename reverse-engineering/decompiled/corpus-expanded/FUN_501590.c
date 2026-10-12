/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501590; label: FUN_00501590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00501590(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  int local_8;
  
  piVar3 = *(int **)(param_1 + 0xa8);
  piVar4 = *(int **)(*(int *)(param_1 + 0x58) + 0x1c);
  uVar7 = 0;
  if ((char)piVar4[2] != '\0') {
    local_8 = 0;
    do {
      iVar1 = *piVar3 + uVar7 * 8;
      uVar6 = (uint)*(byte *)(*piVar4 + local_8 + 0x59);
      iVar2 = piVar4[1] + uVar6 * 0xc;
      if ((((*(byte *)(piVar4[1] + 4 + uVar6 * 0xc) & 2) != 0) && (*(ushort *)(iVar2 + 6) != 0xffff)
          ) && (pcVar5 = *(code **)(DAT_009213c0 + 8 + (uint)*(ushort *)(iVar2 + 6) * 0x14),
               pcVar5 != (code *)0x0)) {
        (*pcVar5)(param_1,piVar4,iVar1,*piVar4 + local_8);
      }
      if (((*(byte *)(iVar2 + 4) & 0x10) != 0) && (*(short *)(iVar2 + 6) != -1)) {
        *(undefined4 *)(iVar1 + 4) = 0xffffffff;
      }
      local_8 = local_8 + 100;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(byte *)(piVar4 + 2));
  }
  return;
}

