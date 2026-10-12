/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4277d0; label: FUN_004277d0
 */

void FUN_004277d0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = &DAT_0093d7f0;
  do {
    if ((*piVar3 != 0) && ((*(uint *)(*piVar3 + 0x1fc) & 0x1000) == 0)) {
      piVar2 = &DAT_0093d7f8;
      do {
        iVar1 = *piVar2;
        if (((((iVar1 != 0) && ((*(byte *)(iVar1 + 0x7c5) & 2) == 0)) &&
             ((*(uint *)(iVar1 + 0xeec) & 0x4000000) == 0)) &&
            ((*(char *)(iVar1 + 0x7b5) != '$' && (*(char *)(iVar1 + 0x7b5) != '\x1f')))) &&
           ((*(char *)(iVar1 + 0x281) != '\0' ||
            ((*(char *)(iVar1 + 0xe32) == '\x01' &&
             (0.0 < *(float *)(*(int *)(*(int *)(iVar1 + 0x54) + 0x24) + 0x28))))))) {
          FUN_00487ca0(*piVar3,iVar1,1);
        }
        piVar2 = piVar2 + 1;
      } while ((int)piVar2 < 0x93d810);
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x93d7f8);
  return;
}

