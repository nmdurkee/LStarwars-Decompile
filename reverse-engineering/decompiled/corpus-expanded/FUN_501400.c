/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501400; label: FUN_00501400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_00501400(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *unaff_ESI;
  int local_4;
  
  piVar5 = param_1;
  puVar6 = (uint *)0x0;
  if (((param_1 != (int *)0x0) && ((char)param_1[2] != '\0')) && (unaff_ESI != (uint *)0x0)) {
    puVar6 = (uint *)(*unaff_ESI + 0xf & 0xfffffff0);
    *unaff_ESI = (uint)(puVar6 + 1);
    *puVar6 = 0;
    uVar7 = *unaff_ESI + 0xf & 0xfffffff0;
    *unaff_ESI = uVar7;
    *puVar6 = uVar7;
    *unaff_ESI = *unaff_ESI + (uint)*(byte *)(param_1 + 2) * 8;
    _memset((void *)*puVar6,0,(uint)*(byte *)(param_1 + 2) * 8);
    piVar1 = param_1 + 2;
    param_1 = (int *)0x0;
    if ((char)*piVar1 != '\0') {
      local_4 = 0;
      do {
        iVar8 = *piVar5 + local_4;
        iVar2 = *puVar6 + (int)param_1 * 8;
        bVar3 = *(byte *)(piVar5[1] + (uint)*(byte *)(iVar8 + 0x59) * 0xc + 4);
        if ((bVar3 & 1) == 0) {
          if ((bVar3 & 2) == 0) {
            if ((bVar3 & 0x10) == 0) {
              if ((bVar3 & 8) == 0) {
                if ((bVar3 & 4) != 0) {
                  uVar7 = *unaff_ESI + 0xf & 0xfffffff0;
                  *unaff_ESI = uVar7;
                  *(uint *)(iVar2 + 4) = uVar7;
                  *unaff_ESI = *unaff_ESI + 0x10;
                  puVar4 = *(undefined4 **)(iVar2 + 4);
                  *puVar4 = 0;
                  puVar4[1] = 0;
                  puVar4[2] = 0;
                  puVar4[3] = 0;
                }
              }
              else {
                uVar7 = *unaff_ESI + 3 & 0xfffffffc;
                *unaff_ESI = uVar7;
                *(uint *)(iVar2 + 4) = uVar7;
                *unaff_ESI = *unaff_ESI + 0x18;
                puVar4 = *(undefined4 **)(iVar2 + 4);
                *puVar4 = 0;
                puVar4[1] = 0;
                puVar4[2] = 0;
                puVar4[3] = 0;
                puVar4[4] = 0;
                puVar4[5] = 0;
                if (*(char *)(iVar8 + 0x5b) != '\0') {
                  *(int *)(*(int *)(iVar2 + 4) + 0x14) = iVar8;
                }
              }
            }
            else {
              *(undefined4 *)(iVar2 + 4) = 0xffffffff;
            }
          }
        }
        else if ((*(byte *)(iVar8 + 0x58) & 0x20) != 0) {
          *(undefined4 *)(iVar2 + 4) = 0xffffffff;
        }
        local_4 = local_4 + 100;
        param_1 = (int *)((int)param_1 + 1);
      } while ((int)param_1 < (int)(uint)*(byte *)(piVar5 + 2));
    }
  }
  return puVar6;
}

