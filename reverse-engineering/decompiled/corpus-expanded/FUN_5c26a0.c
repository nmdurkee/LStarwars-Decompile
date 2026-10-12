/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c26a0; label: FUN_005c26a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c26a0(void)

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

