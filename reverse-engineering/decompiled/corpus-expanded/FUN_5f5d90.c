/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5d90; label: FUN_005f5d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f5d90(void)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_005f5ce0();
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  *(undefined4 *)(in_ECX + 0x810) = 0x40800000;
  *(undefined4 *)(in_ECX + 0x808) = 0;
  *(undefined4 *)(in_ECX + 0x710) = 0;
  *(undefined4 *)(in_ECX + 0x814) = 0x3e800000;
  *(undefined4 *)(in_ECX + 0x800) = 0;
  *(undefined4 *)(in_ECX + 0x804) = 0;
  *(undefined4 *)(in_ECX + 0x80c) = 0x3f4ccccd;
  *(undefined4 *)(in_ECX + 0x824) = 0;
  *(undefined4 *)(in_ECX + 0x818) = 0;
  *(undefined4 *)(in_ECX + 0x70c) = 2;
  *(undefined4 *)(in_ECX + 0x81c) = 0x42c80000;
  *(undefined4 *)(in_ECX + 0x820) = 0x42dc0000;
  return;
}

