/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2b40; label: FUN_006e2b40
 */

undefined4 FUN_006e2b40(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 1;
  if (((((bool)*(char *)(in_ECX + 0x65c) == (*(int *)(in_ECX + 0x158) == 1)) &&
       (*(int *)(in_ECX + 0x660) == *(int *)(in_ECX + 0x620))) &&
      (*(char *)(in_ECX + 0x664) == *(char *)(in_ECX + 0x634))) &&
     ((*(int *)(in_ECX + 0x668) == *(int *)(in_ECX + 0x638) &&
      (*(short *)(in_ECX + 0x66c) == *(short *)(in_ECX + 0x6e4))))) {
    uVar1 = 0;
  }
  return uVar1;
}

