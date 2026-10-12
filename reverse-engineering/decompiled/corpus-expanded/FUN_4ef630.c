/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef630; label: FUN_004ef630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef630(void)

{
  undefined4 *puVar1;
  undefined4 *_Memory;
  
  _Memory = DAT_0088ab18;
  while (_Memory != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*_Memory;
    _free(_Memory);
    _Memory = puVar1;
  }
  return;
}

