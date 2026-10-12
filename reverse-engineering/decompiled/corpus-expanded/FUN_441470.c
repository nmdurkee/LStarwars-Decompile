/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441470; label: FUN_00441470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441470(void)

{
  int iVar1;
  int in_stack_00000010;
  
  if (((DAT_0093d810 != 0) && (*(char *)(DAT_0093d810 + 0x7b5) == 'a')) &&
     (*(int *)(DAT_0093d810 + 0x798) != 0)) {
    if (in_stack_00000010 == 0) goto LAB_004414a6;
    iVar1 = FUN_004f8b10(*(int *)(DAT_0093d810 + 0x798) + 0x40,in_stack_00000010);
    if (iVar1 == 0) goto LAB_004414a6;
  }
  if (((DAT_0093d814 != 0) && (*(char *)(DAT_0093d814 + 0x7b5) == 'a')) &&
     (*(int *)(DAT_0093d814 + 0x798) != 0)) {
    if (in_stack_00000010 != 0) {
      iVar1 = FUN_004f8b10(*(int *)(DAT_0093d814 + 0x798) + 0x40,in_stack_00000010);
      if (iVar1 != 0) goto LAB_004414db;
    }
LAB_004414a6:
    return (float10)1;
  }
LAB_004414db:
  return (float10)0;
}

