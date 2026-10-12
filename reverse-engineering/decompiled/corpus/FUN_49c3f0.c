/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49c3f0; label: FUN_0049c3f0
 */

uint FUN_0049c3f0(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  
  if ((((((*(uint *)(in_EAX + 0x1fc) & 1) != 0) && ((*(uint *)(in_EAX + 0x1fc) & 0x1000) != 0)) &&
       (*(char *)(in_EAX + 0x28b) == '\0')) && (*(char *)(in_EAX + 0x281) != '\0')) &&
     (((in_ECX == 0 || (in_EAX != in_ECX)) &&
      ((*(char *)(in_EAX + 0x280) == -1 && ((*(uint *)(in_EAX + 0xeec) & 0x8000000) == 0)))))) {
    iVar2 = FUN_0058b7f0();
    if (((((iVar2 == 0) && (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x104) != 0)) &&
         ((cVar1 = *(char *)(in_EAX + 0x7b5), cVar1 != '9' &&
          (((cVar1 != '<' && (cVar1 != ';')) && (cVar1 != '\x17')))))) &&
        (((cVar1 != 'A' && (cVar1 != '\x0f')) &&
         ((cVar1 != 'G' &&
          ((cVar1 != 'F' && ((*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 0x10) == 0)))))))) &&
       ((iVar2 = *(int *)(*(int *)(in_EAX + 0x54) + 0x24), (*(uint *)(iVar2 + 0x90) & 0x8000) == 0
        && ((*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0)))) {
      return ~(*(uint *)(iVar2 + 0x94) >> 9) & 1;
    }
  }
  return 0;
}

