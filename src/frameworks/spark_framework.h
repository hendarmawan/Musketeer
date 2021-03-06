// Copyright (c) 2015 Ionel Gog <ionel.gog@cl.cam.ac.uk>

/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR
 * A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 * See the Apache Version 2.0 License for specific language governing
 * permissions and limitations under the License.
 */

#ifndef MUSKETEER_SPARK_FRAMEWORK_H
#define MUSKETEER_SPARK_FRAMEWORK_H

#include "frameworks/framework_interface.h"

#include <string>

#include "base/common.h"
#include "base/utils.h"
#include "frameworks/spark_dispatcher.h"
#include "translation/translator_spark.h"

namespace musketeer {
namespace framework {

class SparkFramework: public FrameworkInterface {
 public:
  SparkFramework();
  string Translate(const op_nodes& dag, const string& relation);
  void Dispatch(const string& binary, const string& relation);
  FmwType GetType();
  uint32_t ScoreDAG(const node_list& node_list, const relation_size& rel_size);
  double ScoreOperator(shared_ptr<OperatorNode> op_node,
                       const relation_size& rel_size);
  double ScoreClusterState();
  bool CanMerge(const op_nodes& dag, const node_set& to_schedule,
                int32_t num_ops_to_schedule);
  double ScoreCompile();
  double ScorePull(uint64_t data_size_kb);
  double ScoreLoad(uint64_t data_size_kb);
  double ScoreRuntime(uint64_t data_size_kb, const node_list& nodes,
                      const relation_size& rel_size);
  double ScorePush(uint64_t data_size_kb);
  double ScoreMapOperator(OperatorInterface* op, const relation_size& rel_size);
  double ScoreJoinOperator(OperatorInterface* op, const relation_size& rel_size);
  double ScoreMaxMinOperator(OperatorInterface* op, const relation_size& rel_size);
};

} // namespace framework
} // namespace musketeer
#endif
