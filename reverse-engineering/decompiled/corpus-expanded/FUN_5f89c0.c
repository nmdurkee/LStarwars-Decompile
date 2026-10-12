/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f89c0; label: FUN_005f89c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f89c0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 2:
    D3DPERF_BeginEvent(0xffffffff,L"3D render");
    return;
  case 3:
    D3DPERF_BeginEvent(0xffffffff,L"Post-processing-effect render");
    return;
  case 4:
    D3DPERF_BeginEvent(0xffffffff,L"Shadow render");
    return;
  case 5:
    D3DPERF_BeginEvent(0xffffffff,L"Deferred shading");
    return;
  case 6:
    D3DPERF_BeginEvent(0xffffffff,L"bloom/dof");
  }
  return;
}

