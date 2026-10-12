/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8a30; label: D3D9.DLL::D3DPERF_EndEvent
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void D3DPERF_EndEvent(void)

{
                    /* WARNING: Could not recover jumptable at 0x00715760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DPERF_EndEvent();
  return;
}

