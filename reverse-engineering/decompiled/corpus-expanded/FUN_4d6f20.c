/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d6f20; label: FUN_004d6f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d6f20(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  undefined4 *in_ECX;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(in_EAX + 0x54) + 0x24);
  iVar3 = (int)*(char *)(iVar2 + 0x10a);
  if (((((iVar3 == -1) || (*(int *)(*(int *)(in_EAX + 0x50) + 0x14 + iVar3 * 4) == 0)) ||
       (*(char *)(in_EAX + 0x28c) == '\0')) &&
      (((iVar3 = (int)*(char *)(iVar2 + 0xfc), iVar3 == -1 ||
        (*(int *)(*(int *)(in_EAX + 0x50) + 0x14 + iVar3 * 4) == 0)) ||
       (*(char *)(in_EAX + 0x28c) == '\0')))) &&
     (((iVar3 = (int)*(char *)(iVar2 + 0xf8), iVar3 == -1 ||
       (*(int *)(*(int *)(in_EAX + 0x50) + 0x14 + iVar3 * 4) == 0)) ||
      (*(char *)(in_EAX + 0x28c) == '\0')))) {
    *in_ECX = *(undefined4 *)(in_EAX + 0x80);
    in_ECX[1] = *(float *)(in_EAX + 0xb0) + *(float *)(in_EAX + 0x84);
    in_ECX[2] = *(undefined4 *)(in_EAX + 0x88);
    return;
  }
  puVar1 = (undefined4 *)(iVar3 * 0x40 + 0x834 + in_EAX);
  *in_ECX = *puVar1;
  in_ECX[1] = puVar1[1];
  in_ECX[2] = puVar1[2];
  return;
}

