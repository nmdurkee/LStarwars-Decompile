/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0e10; label: FUN_004f0e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f0e10(int param_1)

{
  int in_EAX;
  int iVar1;
  char *pcVar2;
  int in_EDX;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = in_EAX + -0x18;
  iVar1 = 0;
  pcVar2 = (char *)(in_EDX + 0x18);
  while (iVar3 != 0) {
    *pcVar2 = *pcVar2 - *(char *)(iVar1 + param_1);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
    if (unaff_EDI <= iVar1) {
      iVar1 = 0;
    }
    pcVar2 = pcVar2 + 1;
  }
  *(uint *)(in_EDX + 0x10) = *(uint *)(in_EDX + 0x10) & 0xfffffffe;
  return;
}

