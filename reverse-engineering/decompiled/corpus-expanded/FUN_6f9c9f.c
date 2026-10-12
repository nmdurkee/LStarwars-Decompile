/* Ghidra pseudocode, not original source.
 * ev_77aeb2367ed99f8a41c442dae19643b7a9da5543c353c848e7914996f03c14a2
 * Entry: 0x6f9c9f; label: __raise_excf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __raise_excf
   
   Library: Visual Studio 2005 Release */

void __raise_excf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  __raise_exc_ex(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}

