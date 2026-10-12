/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x5552b0; label: FUN_005552b0
 */

void FUN_005552b0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  float10 fVar7;
  
  if (((param_3 != 0) && (*(int *)(param_1 + 0x46e0) != 0)) &&
     (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0')) {
    iVar5 = 0;
    pbVar6 = (byte *)(param_3 + 6);
    iVar4 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x46e0) + iVar5;
      if ((*(byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar5) & 1) != 0) {
        *pbVar6 = *pbVar6 | 1;
        *(undefined2 *)(pbVar6 + -2) = *(undefined2 *)(iVar1 + 0x7e);
        bVar2 = (~((char)((uint)(int)*(char *)(iVar1 + 0xac) >> 1) * '\x04') ^ *pbVar6) & 4 ^
                *pbVar6;
        *pbVar6 = bVar2;
        *pbVar6 = (~((char)((uint)(int)*(char *)(iVar1 + 0xac) >> 2) * '\x02') ^ bVar2) & 2 ^ bVar2;
        iVar3 = FUN_005a0f10(*(undefined4 *)(iVar1 + 0x68));
        if (iVar3 != 0) {
          pbVar6[-0xffffffff00000006] = 0;
          pbVar6[-0xffffffff00000005] = 0;
          pbVar6[-0xffffffff00000004] = 0;
          pbVar6[-0xffffffff00000003] = 0;
        }
        if (*(int *)(*(int *)(iVar1 + 0x68) + 0xc) == 2) {
          fVar7 = (float10)1;
        }
        else {
          if (*(int *)(iVar1 + 0x68) == 0) goto LAB_00555373;
          fVar7 = (float10)FUN_005a13a0(*(undefined4 *)(iVar1 + 0x6c));
        }
        *(float *)(pbVar6 + -6) = (float)fVar7;
      }
LAB_00555373:
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x304;
      pbVar6 = pbVar6 + 8;
    } while (iVar4 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
  }
  return;
}

