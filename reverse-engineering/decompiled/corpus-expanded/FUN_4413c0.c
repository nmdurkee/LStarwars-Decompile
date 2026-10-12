/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4413c0; label: FUN_004413c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004413c0(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if (((in_EAX != 0) && (*(char *)(in_EAX + 0x7b5) == '\v')) && (*(int *)(in_EAX + 0x798) != 0)) {
    if ((in_ECX != 0) && (iVar1 = FUN_004f8b10(*(int *)(in_EAX + 0x798) + 0x40), iVar1 != 0)) {
      return 0;
    }
    return 1;
  }
  return 0;
}

