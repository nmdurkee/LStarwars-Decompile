/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69ef10; label: FUN_0069ef10
 */

void FUN_0069ef10(void)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x18) <= *(int *)(unaff_ESI + 0x1c) + in_ECX) {
    iVar1 = *(int *)(unaff_ESI + 0x18) + 0x20 + in_ECX;
    *(int *)(unaff_ESI + 0x18) = iVar1;
    pvVar2 = _realloc(*(void **)(unaff_ESI + 0x10),iVar1 * 4);
    *(void **)(unaff_ESI + 0x10) = pvVar2;
    pvVar2 = _realloc(*(void **)(unaff_ESI + 0x14),*(int *)(unaff_ESI + 0x18) * 8);
    *(void **)(unaff_ESI + 0x14) = pvVar2;
  }
  return;
}

