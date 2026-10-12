/* Ghidra pseudocode, not original source.
 * ev_bde5c5f75e817edbac891f5cdb42210190c78104eb02ca0378b00d023a3e9188
 * Entry: 0x6f6925; label: __fload_withFB
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __fload_withFB
   
   Library: Visual Studio */

uint __fload_withFB(void)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = *(uint *)(in_EDX + 4) & 0x7ff00000;
  if (uVar1 != 0x7ff00000) {
    return uVar1;
  }
  return *(uint *)(in_EDX + 4);
}

