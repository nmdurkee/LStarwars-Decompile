/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547bd0; label: FUN_00547bd0
 */

void FUN_00547bd0(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  undefined4 uVar6;
  
  if ((param_4 != -1) || ((param_3 != 0 && (param_4 = FUN_00650dc0(param_3), param_4 != -1)))) {
    iVar2 = *(int *)(param_1 + 0x4b10);
    iVar3 = 0;
    if (0 < iVar2) {
      psVar5 = (short *)(param_1 + 0x471c);
      do {
        if (*psVar5 == param_4) break;
        iVar3 = iVar3 + 1;
        psVar5 = psVar5 + 8;
      } while (iVar3 < iVar2);
    }
    if (iVar3 < iVar2) {
      cVar1 = *(char *)(iVar3 * 0x10 + 0x471e + param_1);
      if (cVar1 != -1) {
        *(char *)(iVar3 * 0x10 + 0x471e + param_1) = cVar1 + '\x01';
        return;
      }
    }
    else if (iVar2 < 0x40) {
      puVar4 = (undefined4 *)((iVar2 + 0x471) * 0x10 + param_1);
      if (param_2 == (undefined4 *)0x0) {
        *puVar4 = DAT_0095e5c8;
        puVar4[1] = DAT_0095e5cc;
        uVar6 = DAT_0095e5d0;
      }
      else {
        *puVar4 = *param_2;
        puVar4[1] = param_2[1];
        uVar6 = param_2[2];
      }
      puVar4[2] = uVar6;
      *(short *)(*(int *)(param_1 + 0x4b10) * 0x10 + 0x471c + param_1) = (short)param_4;
      *(undefined1 *)(*(int *)(param_1 + 0x4b10) * 0x10 + 0x471e + param_1) = 1;
      *(int *)(param_1 + 0x4b10) = *(int *)(param_1 + 0x4b10) + 1;
    }
  }
  return;
}

