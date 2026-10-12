/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x404850; label: FUN_00404850
 */

undefined4 FUN_00404850(uint param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_EAX;
  int iVar4;
  undefined4 *puVar5;
  int in_EDX;
  
  if (((*(char *)(in_EDX + 0x7d) == '\0') || (*(byte *)(in_EDX + 0x7c) == 0)) ||
     (param_1 != *(byte *)(in_EDX + 0x7c))) {
    if ((int)(uint)*(byte *)(in_EDX + 0x7c) <= (int)param_1) {
      return 0;
    }
    piVar1 = (int *)(in_EDX + param_1 * 0x14);
    cVar2 = (char)piVar1[1];
    if (cVar2 == '\0') {
      puVar5 = (undefined4 *)(*piVar1 + 0x80);
    }
    else if (cVar2 == '\x01') {
      puVar5 = (undefined4 *)(*piVar1 + 0xc);
    }
    else if (cVar2 == '\x02') {
      puVar5 = (undefined4 *)(*piVar1 + 0x4c);
    }
    else {
      if (cVar2 != '\x03') {
        return 0;
      }
      puVar5 = (undefined4 *)*piVar1;
    }
  }
  else {
    iVar3 = *(int *)(in_EDX + 0x84);
    *in_EAX = *(undefined4 *)(iVar3 + 0x80);
    in_EAX[1] = *(undefined4 *)(iVar3 + 0x84);
    in_EAX[2] = *(undefined4 *)(iVar3 + 0x88);
    iVar3 = *(int *)(in_EDX + 0x84);
    if ((*(byte *)(iVar3 + 0xe24) & 8) == 0) {
      return 1;
    }
    iVar4 = (int)*(char *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x112);
    if (iVar4 == -1) {
      return 1;
    }
    if (*(int *)(*(int *)(iVar3 + 0x50) + 0x14 + iVar4 * 4) == 0) {
      return 1;
    }
    puVar5 = (undefined4 *)(iVar4 * 0x40 + 0x834 + iVar3);
  }
  *in_EAX = *puVar5;
  in_EAX[1] = puVar5[1];
  in_EAX[2] = puVar5[2];
  return 1;
}

