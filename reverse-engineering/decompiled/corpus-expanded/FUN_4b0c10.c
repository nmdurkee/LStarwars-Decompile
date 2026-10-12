/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b0c10; label: FUN_004b0c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004b0c10(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar3 = FUN_004a60b0();
  if ((iVar3 != 0) &&
     ((((unaff_EDI == 0 || (unaff_ESI != unaff_EDI)) && (*(char *)(unaff_ESI + 0x280) == -1)) &&
      ((*(uint *)(unaff_ESI + 0xeec) & 0x8000000) == 0)))) {
    iVar3 = FUN_0058b7f0();
    if (((((iVar3 == 0) &&
          (uVar2 = *(uint *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x90),
          (uVar2 & 0x40) == 0)) && (cVar1 = *(char *)(unaff_ESI + 0x7b5), cVar1 != '<')) &&
        ((cVar1 != '\x0f' && (cVar1 != 'G')))) && (cVar1 != 'F')) {
      return ~(uVar2 >> 0xf) & 1;
    }
  }
  return 0;
}

