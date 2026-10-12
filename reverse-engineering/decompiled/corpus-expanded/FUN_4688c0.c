/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x4688c0; label: FUN_004688c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004688c0(undefined4 param_1,int *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  piVar3 = param_2;
  _memset(param_2 + 6,0,0x140);
  iVar7 = *param_2;
  iVar6 = 0;
  if (*(short *)((int)param_2 + 0xe) != 0) {
    do {
      FUN_00467200(param_1);
      if ((param_3 != 0) && (iVar6 < 0x80)) {
        iVar4 = (int)(iVar6 + (iVar6 >> 0x1f & 0x1fU)) >> 5;
        uVar8 = 1 << ((byte)iVar6 & 0x1f);
        *(uint *)(iVar7 + 0xa0) =
             *(uint *)(iVar7 + 0xa0) ^
             ((uint)((*(uint *)(param_3 + 0x10 + iVar4 * 4) & uVar8) != 0) * 2 ^
             *(uint *)(iVar7 + 0xa0)) & 2;
        uVar5 = ((uint)((*(uint *)(param_3 + iVar4 * 4) & uVar8) != 0) ^ *(uint *)(iVar7 + 0xa0)) &
                1 ^ *(uint *)(iVar7 + 0xa0);
        *(uint *)(iVar7 + 0xa0) = uVar5;
        uVar5 = ((uint)((*(uint *)(param_3 + 0x20 + iVar4 * 4) & uVar8) != 0) * 0x200 ^ uVar5) &
                0x200 ^ uVar5;
        *(uint *)(iVar7 + 0xa0) = uVar5;
        uVar5 = ((uint)((*(uint *)(param_3 + 0x30 + iVar4 * 4) & uVar8) != 0) * 0x800 ^ uVar5) &
                0x800 ^ uVar5;
        *(uint *)(iVar7 + 0xa0) = uVar5;
        uVar5 = ((uint)((*(uint *)(param_3 + 0x40 + iVar4 * 4) & uVar8) != 0) * 0x4000 ^ uVar5) &
                0x4000 ^ uVar5;
        *(uint *)(iVar7 + 0xa0) = uVar5;
        uVar5 = ((uint)((*(uint *)(param_3 + 0x50 + iVar4 * 4) & uVar8) != 0) * 0x8000 ^ uVar5) &
                0x8000 ^ uVar5;
        *(uint *)(iVar7 + 0xa0) = uVar5;
        *(uint *)(iVar7 + 0xa0) =
             ((uint)((*(uint *)(param_3 + 0x60 + iVar4 * 4) & uVar8) != 0) * 0x10000 ^ uVar5) &
             0x10000 ^ uVar5;
      }
      cVar2 = *(char *)(iVar7 + 0x7c);
      if ((cVar2 < '\0') || ('\a' < cVar2)) {
        *(undefined4 *)(iVar7 + 0x40) = 0;
      }
      else {
        *(int **)(iVar7 + 0x40) = param_2 + cVar2 * 10 + 6;
        pcVar1 = (char *)((int)(param_2 + cVar2 * 10 + 6) + 0x27);
        *pcVar1 = *pcVar1 + '\x01';
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xa4;
    } while (iVar6 < (int)(uint)*(ushort *)((int)param_2 + 0xe));
  }
  if (param_3 != 0) {
    param_2 = (int *)(param_3 + 0x70);
    param_3 = 8;
    do {
      iVar7 = 0;
      do {
        if ((ushort)*(byte *)((int)param_2 + iVar7) < *(ushort *)((int)piVar3 + 0xe)) {
          iVar6 = (uint)*(byte *)((int)param_2 + iVar7) * 0xa4 + *piVar3;
          if ((*(byte *)(iVar6 + 0xa0) & 0x20) == 0) {
            iVar4 = *(int *)(iVar6 + 0x40);
            if ((iVar4 != 0) && (*(byte *)(iVar4 + 0x26) < 8)) {
              if (*(byte *)(iVar4 + 0x26) != 0) {
                fVar9 = (float10)FUN_00467490();
                *(float *)(iVar4 + 0x20) = (float)(fVar9 + (float10)*(float *)(iVar4 + 0x20));
              }
              *(int *)(*(int *)(iVar6 + 0x40) + (uint)*(byte *)(*(int *)(iVar6 + 0x40) + 0x26) * 4)
                   = iVar6;
              pcVar1 = (char *)(*(int *)(iVar6 + 0x40) + 0x26);
              *pcVar1 = *pcVar1 + '\x01';
              *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x20;
            }
            if ((*(byte *)(iVar6 + 0xa0) & 0x20) == 0) goto LAB_00468b22;
          }
          local_c = 0;
          fVar9 = (float10)FUN_005a1500(*(undefined4 *)(iVar6 + 0x28));
          local_8 = (float)(fVar9 * (float10)*(float *)(*(int *)(iVar6 + 0x40) + 0x20));
          local_4 = 0;
          FUN_005a1480(*(undefined4 *)(iVar6 + 0x28),&local_c);
          *(undefined4 *)(iVar6 + 0x68) = 0x3f800000;
          *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x10);
          *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(iVar6 + 0x14);
          *(undefined4 *)(iVar6 + 0x24) = *(undefined4 *)(iVar6 + 0x18);
          FUN_005a0c20(*(undefined4 *)(iVar6 + 0x28),(undefined4 *)(iVar6 + 0x1c),iVar6 + 0x68,2,1,1
                      );
        }
LAB_00468b22:
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8);
      param_2 = (int *)((int)param_2 + 8);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

