/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x5020e0; label: FUN_005020e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_005020e0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  uint *puVar4;
  uint uVar5;
  uint *in_ECX;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  int local_4;
  
  piVar1 = *(int **)(in_EAX + 0x14);
  puVar4 = (uint *)0x0;
  if (((piVar1 != (int *)0x0) && ((short)piVar1[1] != 0)) && (in_ECX != (uint *)0x0)) {
    puVar4 = (uint *)(*in_ECX + 0xf & 0xfffffff0);
    *in_ECX = (uint)(puVar4 + 1);
    *puVar4 = 0;
    uVar5 = *in_ECX + 0xf & 0xfffffff0;
    *in_ECX = uVar5;
    *puVar4 = uVar5;
    *in_ECX = *in_ECX + (uint)*(ushort *)(piVar1 + 1) * 0x10;
    _memset((void *)*puVar4,0,(uint)*(ushort *)(piVar1 + 1) << 4);
    local_4 = 0;
    if ((short)piVar1[1] != 0) {
      local_c = 0;
      local_10 = 0;
      do {
        iVar8 = *piVar1 + local_10;
        piVar6 = (int *)(*puVar4 + local_c);
        iVar7 = 0;
        if ((param_1 == 0) || (param_1 == *(int *)(iVar8 + 0x44))) {
          iVar2 = *(int *)(iVar8 + 0x44);
          *piVar6 = iVar2;
          if ((iVar2 == 0) || (*(int *)(iVar2 + 0x110) == 0)) {
            piVar6[1] = *(int *)(iVar8 + 0x48);
          }
          else {
            piVar6[1] = 0;
            iVar7 = *(int *)(iVar8 + 0x48);
          }
          piVar6[2] = iVar7;
        }
        else if (*(int *)(iVar8 + 0x48) == 0) {
          FUN_004fff10(*(undefined4 *)(iVar8 + 0x40));
        }
        else {
          *piVar6 = param_1;
          if (*(int *)(param_1 + 0x110) == 0) {
            iVar7 = *(int *)(iVar8 + 0x48);
            iVar2 = *(int *)(*(int *)(iVar8 + 0x44) + 0x28);
            iVar3 = *(int *)(param_1 + 0x28);
            piVar6[2] = 0;
            piVar6[1] = ((iVar7 - iVar2) / 0x4c) * 0x4c + iVar3;
          }
          else {
            iVar7 = *(int *)(iVar8 + 0x48);
            iVar2 = *(int *)(*(int *)(*(int *)(iVar8 + 0x44) + 0x110) + 0x70);
            iVar3 = *(int *)(*(int *)(param_1 + 0x110) + 0x70);
            piVar6[1] = 0;
            piVar6[2] = ((iVar7 - iVar2) / 0xd0) * 0xd0 + iVar3;
          }
          if ((*(byte *)(iVar8 + 0x58) & 2) != 0) {
            *(byte *)((int)piVar6 + 0xd) = *(byte *)(iVar8 + 0x58) & 1;
          }
        }
        local_10 = local_10 + 0x5c;
        local_c = local_c + 0x10;
        local_4 = local_4 + 1;
      } while (local_4 < (int)(uint)*(ushort *)(piVar1 + 1));
    }
  }
  return puVar4;
}

