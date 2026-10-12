/* Ghidra analysis pseudocode, not original source.
 * ev_e9352ae8b4f9815c7bd33078f32d38974dd715693a5fa54abaaf9429a7276350
 * Entry: 0x51a760; label: FUN_0051a760
 */

void FUN_0051a760(void)

{
  char *pcVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (((in_EAX != 0) && (*(int *)(in_EAX + 0x7c) != 0)) && (*(byte *)(in_EAX + 0x10) != 0)) {
    pcVar1 = (char *)(in_EAX + 0x78);
    *pcVar1 = *pcVar1 + '\x01';
    if (*pcVar1 == '\0') {
      *(undefined1 *)(in_EAX + 0x78) = 1;
    }
    *(char *)(in_EAX + 0x79) = *(char *)(in_EAX + 0x79) + '\x01';
    if (*(byte *)(in_EAX + 0x10) <= *(byte *)(in_EAX + 0x79)) {
      *(undefined1 *)(in_EAX + 0x79) = 0;
    }
    iVar2 = (uint)*(byte *)(in_EAX + 0x79) * 0x5c + *(int *)(in_EAX + 0x7c);
    iVar3 = 0;
    if (*(char *)(iVar2 + 0x28) != '\0') {
      do {
        *(undefined1 *)(*(int *)(*(int *)(iVar2 + 0x34) + iVar3 * 4) + 0x17) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)*(byte *)(iVar2 + 0x28));
    }
  }
  return;
}

