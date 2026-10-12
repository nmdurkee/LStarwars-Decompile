/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ec54c; label: vscan_fn
 */

/* Library Function - Single Match
    _vscan_fn
   
   Library: Visual Studio 2005 Release */

undefined4 __cdecl vscan_fn(code *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  FUN_006ff141();
  if ((unaff_ESI == 0) || (param_2 == 0)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*param_1)(&stack0xffffffdc,param_2,param_3,param_4);
  }
  return uVar2;
}

