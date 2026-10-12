/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x708b98; label: __global_unwind2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x708bb0,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}

