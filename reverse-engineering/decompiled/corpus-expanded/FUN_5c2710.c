/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2710; label: D3D9.DLL::D3DPERF_EndEvent
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void D3DPERF_EndEvent(void)

{
                    /* WARNING: Could not recover jumptable at 0x00715760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DPERF_EndEvent();
  return;
}

