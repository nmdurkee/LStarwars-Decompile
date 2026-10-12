/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57c030; label: FUN_0057c030
 */

void FUN_0057c030(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int unaff_ESI;
  int local_4;
  
  piVar2 = *(int **)(in_EAX + 0x1c);
  *(byte *)(unaff_ESI + 0x5c) = *(byte *)(unaff_ESI + 0x5c) | 2;
  iVar3 = FUN_0057bf50(*(undefined4 *)(unaff_ESI + 0x40),*(byte *)(unaff_ESI + 0x5c) & 2,&local_4);
  *(int *)(unaff_ESI + 0x50) = iVar3;
  if (iVar3 == 0) {
    FUN_0057a820(*(undefined4 *)(unaff_ESI + 0x40));
  }
  else if (local_4 != -1) {
    puVar1 = (uint *)(*(int *)(param_1 + 8) + ((int)(local_4 + (local_4 >> 0x1f & 0x1fU)) >> 5) * 4)
    ;
    *puVar1 = *puVar1 | 1 << ((byte)local_4 & 0x1f);
  }
  if ((*(char *)(unaff_ESI + 0x5e) != '\0') && (iVar3 = *(int *)(unaff_ESI + 0x54), iVar3 < 0xff)) {
    *(char *)(unaff_ESI + 0x60) = (char)iVar3;
    *(int *)(unaff_ESI + 0x54) = iVar3 * 100 + *piVar2;
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x60) = 0xff;
  return;
}

