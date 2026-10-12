/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x466820; label: FUN_00466820
 */

void FUN_00466820(int param_1)

{
  if (*(void **)(param_1 + 0x800) != (void *)0x0) {
    _memset(*(void **)(param_1 + 0x800),0,0x630);
  }
  return;
}

