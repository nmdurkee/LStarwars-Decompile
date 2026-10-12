/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566a70; label: FUN_00566a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566a70(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    _memset(param_2,0,0x40);
    _memset((void *)((int)param_2 + 0x40),-1,0x40);
    _memset((void *)((int)param_2 + 0x80),-1,0x40);
    _memset((void *)((int)param_2 + 0xc0),0,0x40);
  }
  return;
}

