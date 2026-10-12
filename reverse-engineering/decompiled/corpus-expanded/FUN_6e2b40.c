/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e2b40; label: FUN_006e2b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

