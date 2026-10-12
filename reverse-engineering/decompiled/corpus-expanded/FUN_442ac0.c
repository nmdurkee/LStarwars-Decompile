/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442ac0; label: FUN_00442ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442ac0(void)

{
  if ((DAT_009553d4 != 0) && (*(char *)(DAT_009553d4 + 0x1d) == '\x02')) {
    return (float10)1;
  }
  return (float10)0;
}

